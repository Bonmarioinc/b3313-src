tools/ido5.3_recomp/cc -c -G 0 -g3 -nostdinc -DTARGET_N64 -D_LANGUAGE_C -mips2 -Iinclude -Ibuild/us -Ibuild/us/include -Isrc -I. -Iinclude/libc -Isrc/game -DVERSION_US=1 -DF3D_OLD=1 -non_shared -Wab,-r4300_mul -Xcpluscomm -Xfullwarn -signed -32 -o surface_collision.o surface_collision.c
#mips64-elf-gcc -Wall -Ofast -mtune=vr4300 -march=vr4300 -mno-local-sdata -mno-gpopt -mabi=32 -fomit-frame-pointer -Iinclude -Ibuild/us -Ibuild/us/include -Isrc -I. -Iinclude/libc -Isrc/game -G0 -DTARGET_N64 -DNON_MATCHING -c surface_collision.c

#cp funny.ld funny.c
#gcc -E funny.c -o funnier.c
#cp funnier.c funnier.ld

#mips64-elf-ld -L build -T undefined_syms.txt -T funnier.ld --no-check-sections -o build/crash_screen.elf crash_screen.o
echo "Done, apply surface_collision.asm to a ROM with armips"
