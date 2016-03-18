res=0

./tinytest_pass
if [ "$?" != "0" ]; then
    res=1
fi

./tinytest_signal
if [ "$?" != "1" ]; then
    res=1
fi

./tinytest_fails
if [ "$?" != "1" ]; then
    res=1
fi

exit $res

