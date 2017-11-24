# Priority of Operators

	&& is lower than <
	
# HashMap 

## std::unordered_map::count

Returns the number of elements with key that compares equivalent to the specified argument, which is either 1 or 0 since this container does not allow duplicates.

## Difference between map and unordered_map

**map** allows to iterate over the elements in a sorted way, but **unordered\_map** does not. This is very important in many situations, for example displaying a collection (e.g. address book). 

This also manifests in other indirect ways like: 

(1) Start iterating from the iterator returned by find(), or

(2) existence of member functions like lower_bound().

Some difference in the worst case search complexity:
+ For **map**, it is O(lg N)
+ For **unordered\_map**, it is O(N). THis may happen when the hash function is not good leading to too many hash collisions.

# Stack

## std::stack::top
Returns reference to the top element in the stack.

## std::stack::pop
Remove the top element
