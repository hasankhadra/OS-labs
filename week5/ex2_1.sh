if [ ! -f ex2.txt ]; then
	echo 0 >> ex2.txt
fi

n=0

for i in {1..50}
do
	n=$(tail -n 1 ex2.txt)
	n=$((n + 1))
	echo $n >> ex2.txt
done