/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charline <charline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:18:40 by charline          #+#    #+#             */
/*   Updated: 2023/07/13 13:50:38 by charline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

// #include <iostream>
// #include <deque>
// #include <algorithm>

// void fordJohnsonSort(std::deque<int>& arr) {
//   // Pairing the elements
//   std::deque<int> sortedPairs;
//   while (!arr.empty()) {
//     int first = arr.front();
//     arr.pop_front();

//     if (!arr.empty()) {
//       int second = arr.front();
//       arr.pop_front();

//       if (first > second) {
//         std::swap(first, second);
//       }

//       sortedPairs.push_back(first);
//       sortedPairs.push_back(second);
//     } else {
//       sortedPairs.push_back(first);
//     }
//   }

//   // Recursive sorting of pairs
//   while (sortedPairs.size() > 1) {
//     std::deque<int> auxPairs;

//     while (!sortedPairs.empty()) {
//       int first = sortedPairs.front();
//       sortedPairs.pop_front();

//       if (!sortedPairs.empty()) {
//         int second = sortedPairs.front();
//         sortedPairs.pop_front();

//         if (first > second) {
//           std::swap(first, second);
//         }

//         auxPairs.push_back(first);
//         auxPairs.push_back(second);
//       } else {
//         auxPairs.push_back(first);
//       }
//     }

//     sortedPairs.swap(auxPairs);
//   }

//   // Insertion of remaining elements
//   while (!arr.empty()) {
//     int element = arr.front();
//     arr.pop_front();

//     std::deque<int>::iterator insertionPos = std::lower_bound(sortedPairs.begin(), sortedPairs.end(), element);
//     sortedPairs.insert(insertionPos, element);
//   }

//   // Print final sorted list
//   for (std::deque<int>::iterator it = sortedPairs.begin(); it != sortedPairs.end(); ++it) {
//     std::cout << *it << " ";
//   }
//   std::cout << std::endl;
// }

// int main()
// {
// 	//   std::deque<int> arr = {5, 2, 8, 3, 1, 6, 7, 4};
// 	//   fordJohnsonSort(arr);
// 	std::deque<int> arr;
// 	int elements[] = {5, 2, 8, 3, 1, 6, 7, 4};
// 	int numElements = sizeof(elements) / sizeof(elements[0]);
// 	for (int i = 0; i < numElements; ++i)
// 	arr.push_back(elements[i]);
// 	fordJohnsonSort(arr);
//  	 return 0;
// }


// // Ford-Johnson algorithm implementation with dequeue and vector
// void fordJohnsonSort(std::deque<int>& arr) {
//   std::vector<int> mainChain;
  
//   // Pairing the elements
//   while (!arr.empty()) {
//     int first = arr.front();
//     arr.pop_front();
    
//     if (!arr.empty()) {
//       int second = arr.front();
//       arr.pop_front();
      
//       if (first > second) {
//         std::swap(first, second);
//       }
      
//       mainChain.push_back(first);
//       mainChain.push_back(second);
//     } else {
//       mainChain.push_back(first);
//     }
//   }
  
//   // Recursive sorting of pairs
//   std::deque<int> sortedPairs(mainChain.begin(), mainChain.end());
//   std::deque<int> auxPairs;
  
//   while (sortedPairs.size() > 1) {
//     while (!sortedPairs.empty()) {
//       int first = sortedPairs.front();
//       sortedPairs.pop_front();
      
//       if (!sortedPairs.empty()) {
//         int second = sortedPairs.front();
//         sortedPairs.pop_front();
        
//         if (first > second) {
//           std::swap(first, second);
//         }
        
//         auxPairs.push_back(first);
//         auxPairs.push_back(second);
//       } else {
//         auxPairs.push_back(first);
//       }
//     }
    
//     sortedPairs.swap(auxPairs);
//   }
  
//   mainChain.swap(sortedPairs);
  
//   // Insertion of remaining elements
//   for (std::deque<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
//     std::deque<int>::iterator insertionPos = std::lower_bound(mainChain.begin(), mainChain.end(), *it);
//     mainChain.insert(insertionPos, *it);
//   }
  
//   // Print final sorted list
//   for (std::vector<int>::iterator it = mainChain.begin(); it != mainChain.end(); ++it) {
//     std::cout << *it << " ";
//   }
//   std::cout << std::endl;
// }

// int main() {
//   std::deque<int> arr = {5, 2, 8, 3, 1, 6, 7, 4};
//   fordJohnsonSort(arr);
//   return 0;
// }

// #include <cstdlib>

int main(int argc, char **argv)
{
	if (argc < 2) // 3?
	{
		std::cout << "ERROR : Wrong number of arguments" << std::endl;
		return (0);
	}
	PmergeMe	pmergeMe;
	try
	{
		for (int i = 1; argv[i]; i++)
			pmergeMe.parse(argv[i]);
		std::list<int>		li;
		std::vector<int>	vec;
		for (int i = 1; argv[i]; i++) //i = 1
		{
			li.push_back(std::atoi(argv[i]));
			vec.push_back(std::atoi(argv[i]));
		}
		// pmergeMe.execLi(li);
		pmergeMe.execVec(vec);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (0);
	}
	return (0);
}