#!/usr/bin/env bash

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

echo "attempting with an empty string:"
echo "  ./replace aa \"\" cc"
./replace aa "" cc

echo "2. empty file test:"
echo "  ./replace resources/empty.txt aa bb"
./replace resources/empty.txt aa bb

echo "ensure that output file got created:"
echo "  find resources/empty.txt.replace"
find resources/empty.txt.replace

echo "ensure that output file is empty:"
echo "  cat -e resources/empty.txt.replace"
cat -e resources/empty.txt.replace

echo "3. Shakespeare test:"
echo "replace all \"the\" entries to  \"T_H_E\":"
echo "  ./replace resources/Shakespeare.txt the T_H_E"
./replace resources/Shakespeare.txt the T_H_E

echo "  diff resources/Shakespeare.txt resources/Shakespeare.txt.replace"
diff -Naur resources/Shakespeare.txt resources/Shakespeare.txt.replace

echo "replace all impossible entries to  #:"
echo "  ./replace resources/Shakespeare.txt \"ggg\" \"#\""
./replace resources/Shakespeare.txt "ggg" "#"

echo "  diff resources/Shakespeare.txt resources/Shakespeare.txt.replace"
diff -Naur resources/Shakespeare.txt resources/Shakespeare.txt.replace

echo "replace all \"e\" entries to  #:"
echo "  ./replace resources/Shakespeare.txt \"e\" \"#\""
./replace resources/Shakespeare.txt "e" "#"

echo "  diff resources/Shakespeare.txt resources/Shakespeare.txt.replace"
diff -Naur resources/Shakespeare.txt resources/Shakespeare.txt.replace

echo "replace all \" \" entries to  #:"
echo "  ./replace resources/Shakespeare.txt \" \" \"#\""
./replace resources/Shakespeare.txt " " "#"

echo "  diff resources/Shakespeare.txt resources/Shakespeare.txt.replace"
diff -Naur resources/Shakespeare.txt resources/Shakespeare.txt.replace

echo "4. Test file that contains single '1' char"
echo "./replace resources/one_char.txt \"1\" \"
██╗  ██╗██████╗
██║  ██║╚════██╗
███████║ █████╔╝
╚════██║██╔═══╝
     ██║███████╗
     ╚═╝╚══════╝.fr\""
./replace resources/one_char.txt "1" "
██╗  ██╗██████╗
██║  ██║╚════██╗
███████║ █████╔╝
╚════██║██╔═══╝
     ██║███████╗
     ╚═╝╚══════╝.fr"
echo "diff resources/one_char.txt resources/one_char.txt.replace"
diff -Naur resources/one_char.txt resources/one_char.txt.replace

echo "The End"

