./corewar -dump $1 $2 $3 $4 $5 > my
./corewar_orig -d $1 $2 $3 $4 $5 > orig
diff my orig > diff
cat diff