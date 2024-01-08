tools/ido5.3_recomp/cc -c -G 0 -O2 -nostdinc -DTARGET_N64 -D_LANGUAGE_C -mips2 -Iinclude -Ibuild/us -Ibuild/us/include -Isrc -I. -Iinclude/libc -Isrc/game -DVERSION_US=1 -DF3D_OLD=1 -non_shared -Wab,-r4300_mul -Xcpluscomm -Xfullwarn -signed -32 -o bhvscripts.o bhvscripts.c
tools/ido5.3_recomp/cc -c -G 0 -O2 -nostdinc -DTARGET_N64 -D_LANGUAGE_C -mips2 -Iinclude -Ibuild/us -Ibuild/us/include -Isrc -I. -Iinclude/libc -Isrc/game -DVERSION_US=1 -DF3D_OLD=1 -non_shared -Wab,-r4300_mul -Xcpluscomm -Xfullwarn -signed -32 -o bhv.o bhv.c

tools/ido5.3_recomp/cc -c -G 0 -O2 -nostdinc -DTARGET_N64 -D_LANGUAGE_C -mips2 -Iinclude -Ibuild/us -Ibuild/us/include -Isrc -I. -Iinclude/libc -Isrc/game -DVERSION_US=1 -DF3D_OLD=1 -non_shared -Wab,-r4300_mul -Xcpluscomm -Xfullwarn -signed -32 -o models.o models.c


echo "Done, apply hopper.asm to a ROM with armips"
