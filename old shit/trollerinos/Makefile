ifneq (,$(call find-command,clang))
  CPP      := clang
  CPPFLAGS := -E -P -x c -Wno-trigraphs $(DEF_INC_CFLAGS)
else
  CPP      := cpp
  CPPFLAGS := -P -Wno-trigraphs $(DEF_INC_CFLAGS)
endif




tools/ido5.3_recomp/cc -c -G 0 -O2 -nostdinc -DTARGET_N64 -D_LANGUAGE_C -mips2 -Iinclude -Ibuild/us -Ibuild/us/include -Isrc -I. -Iinclude/libc -DVERSION_US=1 -DF3D_OLD=1 -non_shared -Wab,-r4300_mul -Xcpluscomm -Xfullwarn -signed -32 -o crash_screen.o crash_screen.c

# Run linker script through the C preprocessor
funnier.ld: funny.ld
	$(V)$(CPP) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d -o $@ $<

mips64-elf-ld -L build -T undefined_syms.txt -T funnier.ld --no-check-sections -o build/crash_screen.elf crash_screen.o -lultra -lgoddard
