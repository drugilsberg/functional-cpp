/* 
 * File:   FunctionalUtils.hpp
 * Author: manica
 *
 * Created on September 11, 2015, 2:05 PM
 */

#ifndef FUNCTIONALUTILS_HPP
#define	FUNCTIONALUTILS_HPP

#include<algorithm>
#include<functional>
#include<utility>

class FunctionalUtils {
public:

    template < template <typename, typename> class Container,
    typename IType, typename IAllocator = std::allocator<IType>,
    typename OType, typename OAllocator = std::allocator<OType> >
    static Container<OType, OAllocator> map(const Container<IType, IAllocator> & input, const std::function<OType(IType)> & func) {
        Container<OType, OAllocator> output(input.size());
        std::transform(input.begin(), input.end(), output.begin(), func);
        return output;
    }

    template < template <typename, typename> class Container,
    typename FirstType, typename FirstAllocator = std::allocator<FirstType>,
    typename SecondType, typename SecondAllocator = std::allocator<SecondType>,
    typename OType = std::pair<FirstType, SecondType>, typename OAllocator = std::allocator<OType> >
    static Container< OType, OAllocator > zip(const Container<FirstType, FirstAllocator> & aContainer, 
    const Container<SecondType, SecondAllocator> & anotherContainer) {

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



};


#endif	/* FUNCTIONALUTILS_HPP */

