all:
	@ gcc ls.c -o LS
	@ gcc rm.c -o rmv
	@ gcc mkdir.c -o mkdir
	@ gcc date.c -o date
	@ gcc cat.c -o cat
	@ gcc Main.c -o Main
	@ ./Main

clean:
	@ rm LS rmv mkdir date cat Main
