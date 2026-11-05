#!/bin/bash

cat <<THE_END
<html>
<head>
<title>Gallery</title>
</head>
<body>
<table>
THE_END

if test ! -d mini
then
    mkdir mini
fi

while [ "$#" != 0 ]
do
    MINIATURA='mini/'$(echo $1 | sed 's/jpg$/png/')
    convert -resize '20%' "$1" "$MINIATURA" 2>/dev/null
    echo '<tr>'
    echo '<td>'
    echo '<a href="'$1'">'
    echo '<img src="'$MINIATURA'">'
    echo '</a>'
    echo '</td>'
    echo '</tr>'
    shift
done

cat <<THE_END
</table>
</body>
</html>
THE_END
