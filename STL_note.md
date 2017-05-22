# Introduction
The STL (Standard Template Library) consists of:

* algorithms

* iterator

* container

* function object

# Container Overview
A container holds a sequence of objects.

* ***Sequence containers*** provide access to (half-open) sequences of elements:

	+ vector<T,A>
	+ list<T,A>
	+ forward_list<T,A>
	+ deque<T,A>

The A template argument is the allocator that the container uses to acquire and release memory.

* ***Associative container*** provide associative lookup based on a key:
	* These containers are usually implemented as balanced binary trees (usually red-black trees):
		+ map<K, V, C, A>
		+ multimap<K, V, C, A>
		+ set<K, C, A>
		+ multiset<K, C, A>
	* These containers are implemented as hash tables with linked overﬂow:
		+ unordered_map<K, V, H, E, A>
		+ unordered_multimap<K, V, H, E, A>
		+ unordered_set<K, H, E, A>
		+ unordered_multiset<K, H, E, A>

C is the type of the comparison; A is the allocator type. 

* ***Container Adaptor***
	* priority_queue<T, C, cmp>
	* queue<T, C>
	* stack<T, C>

# unordered_set
## Intro
Unordered sets are containers that store unique elements in no particular order, and which allow for fast retrieval of individual elements based on their value.

In an unordered\_set, the value of an element is at the same time its key, that identifies it uniquely. Keys are immutable, therefore, the elements in an unordered_set cannot be modified once in the container - they can be inserted and removed, though.

Internally, the elements in the unordered_set are not sorted in any particular order, but organized into buckets depending on their hash values to allow for fast access to individual elements directly by their values (with a constant average time complexity on average).

unordered_set containers are faster than set containers to access individual elements by their key, although they are generally less efficient for range iteration through a subset of their elements.

Iterators in the container are at least forward iterators.
## Insert
* Inserts new elements in the unordered_set.

* Each element is inserted only if it is not equivalent to any other element already in the container (elements in an unordered_set have unique values).