for((i=1;i<=10;i++)); do
	./generator > input1.txt
	./D < input1.txt > output1.txt
done