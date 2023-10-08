// #include "PmergeMe.hpp"

// std::vector<int> PmergeMe::vecSequence;
// std::list<int> PmergeMe::listSequence;

// bool PmergeMe::containsOnlyPosDigitsAndSpaces(const std::string& str) {
//     for(size_t i = 0; i < str.length(); ++i) {
//         if(!std::isdigit(str[i]) && str[i] != ' ' && str[i] != '+')
//             return false;
//         if(str[i] == '+' && !std::isdigit(str[i + 1]))
//             return false;
//     }
//     return true;
// }

// void PmergeMe::fillIntContainers(const std::string& str) {
//     std::stringstream ss(str), sp(str);
//     std::string tmp;
//     long overflow;
//     int num;

//     while(sp >> tmp) {
//         ss >> overflow;
//         if(overflow <= 0)
//             throw std::logic_error (ERROR_MESSAGE("negative number or zero."));
//         if(overflow > std::numeric_limits<int>::max() || tmp.size() > 12)
//             throw std::logic_error (ERROR_MESSAGE("number is too large for int."));
//         num = static_cast<int>(overflow);
//         vecSequence.push_back(num);
//         listSequence.push_back(num);

//         if(sp.peek() == ' ') {
//             ss.ignore();
//             sp.ignore();
//         }
//     }

//     if(vecSequence.empty() || listSequence.empty())
//         throw std::logic_error(ERROR_MESSAGE("empty sequence."));
// }

// void PmergeMe::vectorInsertion(std::vector<int>& nums) {
//     for(size_t i = 1; i < nums.size(); ++i) {
//         int j = i;
//         while(j > 0 && nums[j] < nums[j - 1]) {
//             std::swap(nums[j], nums[j - 1]);
//             j--;
//         }
//     }
// }

// void PmergeMe::vectorInsert(std::vector<int>& bigNumbers, std::vector<int> smallNumbers) {
//     int n = 0;
//     int power = 0;
//     size_t start_index = 0;
//     size_t end_index = 0;

//     for(size_t i = 0; i < smallNumbers.size();) {
//         ++power;
//         n = pow(2, power) - n;
//         start_index += n;
//         end_index = start_index - n;

//         if(start_index > smallNumbers.size())
//             start_index = smallNumbers.size();

//         for(size_t j = start_index - 1; j >= end_index;) {
//             bigNumbers.insert(std::upper_bound(bigNumbers.begin(), bigNumbers.end(), smallNumbers[j]), smallNumbers[j]);
//             ++i;
//             if(j == 0)
//                 break;
//             --j;
//         }
//     }
// }

// void PmergeMe::vectorFordJohnsonAlgorithm(std::vector<int>& nums) {
//     int unpaired;
//     std::vector<int> bigNumbers, smallNumbers;
//     size_t size = nums.size() / 2 + (nums.size() % 2);

//     unpaired = ((nums.size() % 2 == 0) ? -1 : nums[nums.size() - 1]);
//     if(nums.size() == 2 || nums.size() == 3) {
//         vectorInsertion(nums);
//         return;
//     }

//     for(size_t i = 0; i < size; ++i) {
//         if(i != size - 1 || nums.size() % 2 == 0) {
//             int n = nums[i * 2], m = nums[i * 2 + 1];
//             if(n > m)
//                 std::swap(n, m);
//             bigNumbers.push_back(m);
//             smallNumbers.push_back(n);
//         }
//     }
//     if(unpaired != -1)
//         smallNumbers.push_back(unpaired);
//     vectorFordJohnsonAlgorithm(bigNumbers);
//     vectorInsert(bigNumbers, smallNumbers);
//     nums = bigNumbers;
// }

// void PmergeMe::listInsertion(std::list<int>& nums) {
//     for(std::list<int>::iterator it = std::next(nums.begin()); it != nums.end(); ++it) {
//         int tmp = *it;
//         std::list<int>::iterator j = it;
//         while(j != nums.begin() && *std::prev(j) > tmp) {
//             *j = *std::prev(j);
//             --j;
//         }
//         *j = tmp;
//     }
// }

// void PmergeMe::listInsert(std::list<int>& bigNumbers, std::list<int> smallNumbers) {
//     int n = 0;
//     int power = 0;
//     std::list<int>::iterator start_it = bigNumbers.begin();
//     std::list<int>::iterator end_it = start_it;

//     for(std::list<int>::iterator it = smallNumbers.begin(); it != smallNumbers.end();) {
//         ++power;
//         n = pow(2, power) - n;
//         std::advance(start_it, n);
//         end_it = start_it;
//         std::advance(end_it, -n);

//         if(start_it != smallNumbers.end())
//             start_it = smallNumbers.end();

//         for(std::list<int>::iterator j = std::prev(start_it); j != std::prev(end_it);) {
//             bigNumbers.insert(std::upper_bound(bigNumbers.begin(), bigNumbers.end(), *j), *j);
//             ++it;
//             if(j == smallNumbers.begin())
//                 break;
//             --j;
//         }
//     }
// }

// void PmergeMe::listFordJohnsonAlgorithm(std::list<int>& nums) {
//     int unpaired;
//     std::list<int> bigNumbers, smallNumbers;
//     size_t size = nums.size() / 2 + (nums.size() % 2);

//     unpaired = ((nums.size() % 2 == 0) ? -1 : nums.back());

//     if(nums.size() == 2 || nums.size() == 3) {
//         listInsertion(nums);
//         return;
//     }

//     for(size_t i = 0; i < size; ++i) {
//         if(i != size - 1 || nums.size() % 2 == 0) {
//             int n = *std::next(nums.begin(), i * 2);
//             int m = *std::next(nums.begin(), i * 2 + 1);
//             if(n > m)
//                 std::swap(n, m);
//                 bigNumbers.push_back(m);
//                 smallNumbers.push_back(n);
//             }
//         }
//     if(unpaired != -1)
//         smallNumbers.push_back(unpaired);
//     listFordJohnsonAlgorithm(bigNumbers);
//     listInsert(bigNumbers, smallNumbers);
//     nums = bigNumbers;
// }

// double PmergeMe::doListSort() {
//     std::list<int> check(listSequence);

//     clock_t start = clock();
//     if(listSequence.size() != 1) listFordJohnsonAlgorithm(listSequence);
//     clock_t end = clock();
    
//     std::vector<int> tempVector(check.begin(), check.end());
//     std::sort(tempVector.begin(), tempVector.end());

//     std::copy(tempVector.begin(), tempVector.end(), check.begin());
//     if(check != listSequence)
//         throw std::logic_error(ERROR_MESSAGE("vector sort error."));

//     double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;

//     return duration;
// }

// double PmergeMe::doVectorSort() {
//     std::vector<int> check(vecSequence);

//     clock_t start = clock();
//     if(vecSequence.size() != 1) vectorFordJohnsonAlgorithm(vecSequence);
//     clock_t end = clock();
    
//     std::sort(check.begin(), check.end());
//     if(check != vecSequence)
//         throw std::logic_error(ERROR_MESSAGE("vector sort error."));

//     double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;

//     return duration;
// }

// void PmergeMe::printVectorSequence(std::string When) {
//     std::cout<<When<<"\t[std::vector]: ";

//     if(vecSequence.size() <= 13) {
//         for(size_t i = 0; i < vecSequence.size(); ++i) {
//             std::cout<<vecSequence[i];
//             if(i != vecSequence.size() - 1)
//                 std::cout<<" ";
//         }
//     } else {
//         for(size_t i = 0; i < 10; ++i)
//             std::cout<<vecSequence[i]<<" ";

//         std::cout<<"[...] ";

//         for(size_t i = vecSequence.size() - 3; i < vecSequence.size(); ++i) {
//             std::cout<<vecSequence[i];
//             if(i != vecSequence.size() - 1)
//                 std::cout<<" ";
//         }
//     }

//     std::cout<<std::endl;
// }

// void PmergeMe::printListSequence(std::string When) {
    // std::cout<<When<<"\t[std::list]  : ";

    // if(listSequence.size() <= 13) {
    //     for(std::list<int>::iterator it = listSequence.begin(); it != listSequence.end(); ++it) {
    //         std::cout<<*it;
    //         if(it != --listSequence.end())
    //             std::cout<<" ";
    //     }
    // } else {
    //     int printedCount = 0;
    //     for(std::list<int>::iterator it = listSequence.begin(); printedCount != 10 && it != listSequence.end(); ++it) {
    //         ++printedCount;
    //         std::cout<<*it<<" ";
    //     }

    //     std::cout<<"[...] ";

    //     std::list<int>::iterator lastButOne = listSequence.end();
    //     std::advance(lastButOne, -3);

    //     for(std::list<int>::iterator it = lastButOne; it != listSequence.end(); ++it) {
    //         std::cout<<*it;
    //         if(it != --listSequence.end())
    //             std::cout<<" ";
    //     }
    // }
    
    // std::cout<<std::endl;
// }

// void PmergeMe::FordJohnsonSort(std::string str) {
//     listSequence.clear();
//     vecSequence.clear();

//     if(str.empty() || !containsOnlyPosDigitsAndSpaces(str))
//         throw std::logic_error(ERROR_MESSAGE("invalid argument."));
    
//     fillIntContainers(str);

//     printVectorSequence("Before");
//     printListSequence("Before");

//     double vectorTime, listTime;
//     vectorTime = doVectorSort();
//     listTime = doListSort();

//     printVectorSequence("After");
//     printListSequence("After");

//     std::cout<<"Time to process a range of "<<vecSequence.size()<<" elements with std::vector :\t"<<vectorTime<<"\tmilliseconds"<<std::endl;
//     std::cout<<"Time to process a range of "<<listSequence.size()<<" elements with std::list   :\t"<<listTime<<"\tmilliseconds"<<std::endl;
// }