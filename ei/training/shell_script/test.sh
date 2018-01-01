echo "Welcome"
var=hi
echo $var
echo "write"
read var
echo $var
if [ -n $var ]
then
   echo "Empty string"
fi
