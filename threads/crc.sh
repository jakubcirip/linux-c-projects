# crc - compile-run-clean

echo "Compiling..."
gcc -o threads threads.c -pthread
sleep 3

echo "Runing threads"
sleep 1
./threads
sleep 1

echo "Cleaning files..."
rm -f threads
sleep 1
echo "Done"