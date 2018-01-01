term=$(tty);
echo $term
while true
do
sleep 2
term=$(tty)
if [ -z term ]
then
	echo "Nop"
else
	echo $term
break
fi
done

echo "###############3"

