contest=abc$1

if [ $contest == abc ];then
echo "invalid argment"
exit 0
fi

mkdir -p $contest

for p in a b c d e f
do
if [ ! -e $contenst/$p.cpp ];then
touch $contenst/$p.cpp
fi
done
echo "done"
exit 1
