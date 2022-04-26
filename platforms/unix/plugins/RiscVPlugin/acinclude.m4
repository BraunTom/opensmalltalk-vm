# To build the RiscVPlugin one must build the Bochs support libraries
if test -f ../../../../processors/riscv_em/build/libriscv_em.a; then
	echo "risv_em library has been built; building RiscVPlugin"
else
	echo "riscv_em library has not been built; not building RiscVPlugin"
	AC_PLUGIN_DISABLE
fi
