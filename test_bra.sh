./corewar -dump $1 $2 $3 $4 $5 > my
./corewar_bra -d $1 $2 $3 $4 $5 > bra
diff my bra > diff
cat diff