#ifndef FIND_H_
#define FIND_H_

#include <vector>
#include <iterator>
#include <algorithm>

template <typename Type>
class Find
{
    public:
        template <typename ForwardIter>
        std::vector<int> operator()(ForwardIter inicio, ForwardIter fin, Type valor)
        {
             std::vector<int> rpt;
             int cont{1};
             while(inicio != fin)
             {
                 *inicio++;
                 cont++;
                 if(*inicio == valor)
                 {
                     rpt.push_back(cont);
                 }
             }
             return rpt;
        }
};

#endif
