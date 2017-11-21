# Parse a vector<string>
```cpp
        for (string op : ops) {
            if (op == "C") {
				...
                continue;				
            }
            if (op == "D") {
				...
			}
            else if (op == "+") {
				...
            }
            else {
				...
            }
   		}
```

# STL: vector<E>
## std::vector::back
Returns reference to the last element in the container.
```cpp
#include <vector>
#include <iostream>
 
int main()
{
    std::vector<char> letters {'o', 'm', 'g', 'w', 't', 'f'};
    if (!letters.empty()) {
        std::cout << "The last character is: " << letters.back() << '\n';
    }
	//Output : The last character is f
}
```

## std::vector::pop_back
removes the last element.
```cpp
            if (op == "C") {
                sum -= rounds.back();
                rounds.pop_back();
                continue;
            }
```

# Clean code 
```cpp
                sum += score = rounds.back() * 2;
				sum += score = rounds[rounds.size() - 1] + rounds[rounds.size() - 2];
				sum += score = stoi(op);
```

# Complex 

## Time Complex

$ O(N) $, where N is the length of ops. We parse through every element in the given array once, and do O(1) work for each element.

## Space Complex
The space used to store our stack.
