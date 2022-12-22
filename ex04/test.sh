#!/usr/bin/env bash
echo "make"
make

echo "make clean"
make clean

echo "1. wrong input test:"

echo "attempting with no args:"
echo "  ./replace"
./replace

echo "attempting with 4 args:"
echo "  ./replace aa bb cc dd"
./replace aa bb cc dd

echo "attempting with nonexistent filename:"
echo "  ./replace aa bb cc"
./replace aa bb cc

echo "attempting with space-empty string:"
echo "  ./replace aa \" \" cc"
./replace aa " " cc

echo "attempting with an empty string:"
echo "  ./replace aa \"\" cc"
./replace aa "" cc

echo "2. empty file test:"
echo "  ./replace empty.txt aa bb"
./replace empty.txt aa bb

echo "ensure that output file got created:"
echo "  find empty.txt.replace"
find empty.txt.replace

echo "ensure that output file is empty:"
echo "  cat -e empty.txt.replace"
cat -e empty.txt.replace

echo "3. Shakespeare test:"
echo "replace all \"the\" entries to  \"T_H_E\":"
echo "  ./replace Shakespeare.txt the T_H_E"
./replace Shakespeare.txt the T_H_E

echo "  diff Shakespeare.txt Shakespeare.txt.replace"
diff -Naur Shakespeare.txt Shakespeare.txt.replace

echo "replace all impossible entries to  #:"
echo "  ./replace Shakespeare.txt \"ggg\" \"#\""
./replace Shakespeare.txt "ggg" "#"

echo "  diff Shakespeare.txt Shakespeare.txt.replace"
diff -Naur Shakespeare.txt Shakespeare.txt.replace

echo "replace all \"e\" entries to  #:"
echo "  ./replace Shakespeare.txt \"e\" \"#\""
./replace Shakespeare.txt "e" "#"

echo "  diff Shakespeare.txt Shakespeare.txt.replace"
diff -Naur Shakespeare.txt Shakespeare.txt.replace

echo "replace all \" \" entries to  #:"
echo "  ./replace Shakespeare.txt \" \" \"#\""
./replace Shakespeare.txt " " "#"

echo "  diff Shakespeare.txt Shakespeare.txt.replace"
diff -Naur Shakespeare.txt Shakespeare.txt.replace

echo "4. Test file that contains single '1' char"
echo "./replace one_char.txt \"1\" \"
██╗  ██╗██████╗
██║  ██║╚════██╗
███████║ █████╔╝
╚════██║██╔═══╝
     ██║███████╗
     ╚═╝╚══════╝.fr\""
./replace one_char.txt "1" "
██╗  ██╗██████╗
██║  ██║╚════██╗
███████║ █████╔╝
╚════██║██╔═══╝
     ██║███████╗
     ╚═╝╚══════╝.fr"
echo "diff one_char.txt one_char.txt.replace"
diff -Naur one_char.txt one_char.txt.replace

echo "The End"

