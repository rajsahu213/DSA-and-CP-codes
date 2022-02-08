for((i=1;i<=1;i++)); do
	echo $i
	./generator > input1.txt
	./B < input1.txt > output1.txt
	./C < input1.txt > output.txt
	diff -w output1.txt output.txt || break
done
	1->1
	2->2 2
	3 -> 1 2 2, 3 3 3
	4-> 4 4 4 4, 1 3 3 3
	5-> 5 5 5 5 5, 1 4 4 4 4, 2 2 3 3 3
	6-> 6 6 6 6 6 6, 1 5 5 5 5 5, 1 2 2 3 3 3, 2 2 4 4 4 4
	7-> 7 7 7 7 7 7 7, 1 6 6 6 6 6 6, 2 2 5 5 5 5 5, 3 3 3 4 4 4 4, 