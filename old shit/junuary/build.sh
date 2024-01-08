for f in actors/**/*.c; do
	if [[ $f != *rgba* ]]; then
		echo "Building $f"
		tools/ido5.3_recomp/cc -c -G 0 -O2 -nostdinc -DTARGET_N64 -D_LANGUAGE_C -mips2 -Iinclude -Ibuild/us -Ibuild/us/include -Isrc -I. -Iinclude/libc -Isrc/game -DVERSION_US=1 -DF3D_OLD=1 -non_shared -Wab,-r4300_mul -Xcpluscomm -Xfullwarn -signed -32 -o $f.o $f
	fi
done

for f in *.c; do
	echo "Building $f"
	tools/ido5.3_recomp/cc -c -G 0 -O2 -nostdinc -DTARGET_N64 -D_LANGUAGE_C -mips2 -Iinclude -Ibuild/us -Ibuild/us/include -Isrc -I. -Iinclude/libc -Isrc/game -DVERSION_US=1 -DF3D_OLD=1 -non_shared -Wab,-r4300_mul -Xcpluscomm -Xfullwarn -signed -32 -o $f.o $f
done

echo "Done, apply junuary hypertroll.asm to a ROM with armips"
