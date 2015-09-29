/* 
 * File:   Functional.hpp
 * Author: manica
 *
 * Created on September 11, 2015, 2:05 PM
 */

#ifndef FUNCTIONAL_HPP
#define	FUNCTIONAL_HPP

#include<algorithm>
#include<functional>
#include<utility>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<iterator>

namespace Functional {


    template <typename Container>
    static std::string mkString(const Container & container, const char* separator = " ") {
        std::ostringstream oss;
        std::copy(container.begin(), container.end() - 1, 
            std::ostream_iterator<typename Container::value_type>(oss, separator)
        );
        oss << container.back();
        return oss.str();
    }

    //template parameters

    template < template <typename, typename> class Container,
    typename IType, typename IAllocator = std::allocator<IType>,
    typename OType, typename OAllocator = std::allocator<OType> >
    //declaration
    static Container<OType, OAllocator> map(const Container<IType, IAllocator> & input, const std::function<OType(IType)> & func) {
        //body
        Container<OType, OAllocator> output(input.size());
        std::transform(input.cbegin(), input.cend(), output.begin(), func);
        return output;
    }

    //template parameters
    template < class Container>
    //declaration
    static Container filter(const Container & input,
            const std::function<bool(typename Container::value_type)> & func) {
        //body
        Container output(input.size());
        typename Container::const_iterator filtered = std::copy_if(input.cbegin(), input.cend(), output.begin(), func);
        output.resize(std::distance(output.cbegin(), filtered));
        return output;
    }

    //template parameters

    template < template <typename, typename> class Container,
    typename FirstType, typename FirstAllocator = std::allocator<FirstType>,
    typename SecondType, typename SecondAllocator = std::allocator<SecondType>,
    typename OType = std::pair<FirstType, SecondType>, typename OAllocator = std::allocator<OType> >
    //declaration
    static Container< OType, OAllocator > zip(const Container<FirstType, FirstAllocator> & aContainer,
            const Container<SecondType, SecondAllocator> & anotherContainer) {
        //body
        const unsigned long int & dimension = std::min(aContainer.size(), anotherContainer.size());
        typename Container<FirstType, FirstAllocator>::const_iterator aIt = aContainer.begin();
        typename Container<SecondType, SecondAllocator>::const_iterator anotherIt = anotherContainer.begin();

        Container<OType, OAllocator> output(dimension);
        typename Container< OType, OAllocator >::iterator oIt = output.begin();
        while (oIt != output.end()) {
            *oIt++ = std::make_pair(*aIt++, *anotherIt++);
        }

        return output;
    }

    //template parameters

    template < template <typename, typename> class Container,
    typename IType, typename IAllocator = std::allocator<IType>,
    typename Key, typename Comparator = std::less<Key>,
    typename KIAllocator = std::allocator< std::pair<const Key, IType> > >
    //declaration
    static std::multimap<Key, IType, Comparator, KIAllocator> keyBy(const Container<IType, IAllocator> & input,
            const std::function< Key(IType)> & func) {
        //body
        std::multimap<Key, IType, Comparator, KIAllocator> output;
        std::transform(input.cbegin(), input.cend(), std::inserter(output, output.end()),
                [&func](const IType & element) {
                    return std::make_pair(func(element), element);
                }
        );
        return output;
    }

    //template parameters

    template < template <typename, typename> class Container,
    typename IType, typename IAllocator = std::allocator<IType>,
    typename Key, typename Comparator = std::less<Key>,
    typename Value = Container<IType, IAllocator>,
    typename KIAllocator = std::allocator< std::pair<const Key, IType> >,
    typename KIType = std::pair<const Key, IType>,
    typename KVAllocator = std::allocator< std::pair<const Key, Value> > >
    //declaration
    static std::map<Key, Value, Comparator, KVAllocator> groupBy(const Container<IType, IAllocator> & input,
            const std::function< Key(IType)> & func) {
        //body
        std::map<Key, Value, Comparator, KVAllocator> output;

        const std::multimap<Key, IType, Comparator, KIAllocator> & mapped = Functional::keyBy(input, func);
        std::set<Key> keys;
        std::transform(mapped.cbegin(), mapped.cend(), std::inserter(keys, keys.begin()),
                [](const KIType & keyValue) {
                    return keyValue.first;
                });

        typedef typename std::multimap<Key, IType, Comparator, KIAllocator>::const_iterator multiConstIt;

        for (const Key & key : keys) {

            std::pair<multiConstIt, multiConstIt> values = mapped.equal_range(key);

            Container<IType,IAllocator> grouped;
            std::transform(values.first, values.second, std::inserter(grouped, grouped.end()),
                [](const KIType & keyValue) {
                    return keyValue.second;
                });

            output.emplace(key, grouped);
        }
        return output;
    }

    template < template <typename, typename> class Container,    
    typename IType, typename IAllocator = std::allocator<IType>,    
    typename Value = Container<IType, IAllocator>,
    typename Key, typename Comparator = std::less<Key>,
    typename KVType = std::pair<const Key, Value>,
    typename KVAllocator = std::allocator< KVType >,
    typename OType, typename KOAllocator = std::allocator< std::pair<const Key, OType> > >        
    //declaration
    static std::map<Key, OType, Comparator, KOAllocator> reduceByKey(const std::map<Key, Container<IType, IAllocator>, Comparator, KVAllocator > & input,
            const std::function< OType(IType, IType)> & func) {
        //body
        std::map<Key, OType, Comparator, KOAllocator> output;

        for (const KVType & keyValue : input) {

            output.emplace(keyValue.first,
                    std::accumulate(keyValue.second.cbegin(), keyValue.second.cend(), OType(), func)
                    );
        }
        return output;
    }

};


#endif	/* FUNCTIONAL_HPP */

