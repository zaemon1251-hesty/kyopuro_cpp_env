projectDir=/home/zaemon1251/workspace/atcoder_cpp
contest=AtCoder/abc/abc$1
targetDir="${projectDir}/$contest"

if [ -z $1 ];then
echo "invalid argment"
exit 0
fi

mkdir -p $targetDir

for p in a b c d e f
do
if [ ! -e "$targetDir/$p.cpp" ];then
touch "$targetDir/$p.cpp"
else
echo "$targetDir/$p.cpp" "already exists"
fi
done
echo "done"
exit 1
