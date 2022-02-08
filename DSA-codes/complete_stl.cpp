TO CONVERT A VECTOR INTO A HEAP

1: make_heap(all(a));
a.push_back(some_element)
2: push_heap(all(a));
3:pop_heap(all(a));
then a.pop_back();

SORTING USING STL

1: sort(all(a));
sort first n1 elements form complete array.
other elements are randomly arranged.
2: partial_sort(a.begin(),a.begin()+n1,a.end());
divide the array into two parts.
nth position will have its original element when sorted
0 to n-1 will be less than nth and n+1 to end will be greater than nth.
3: nth_element(a.begin(),a.begin()+n,a.end());

REARRANGEMENT IN VECTOR

1: reverse(all(a));
n: no of elements to be rotated form begin to end
2: rotate(a.begin(),a.begin()+n,a.end());
