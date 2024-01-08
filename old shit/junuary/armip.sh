armips "junuary hypertroll scuttlebug.asm" -sym "sym.txt"

if [ ! -f "b3313 new.z64" ]; then
    echo "No new romge found, do you have armips installed?"
    exit
fi

chmod +x ./n64crc
./n64crc "b3313 new.z64"
