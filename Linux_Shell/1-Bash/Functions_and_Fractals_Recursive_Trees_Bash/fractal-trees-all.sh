#!/bin/bash

# prints underscores
print_()
{
    if [[ $# -eq 1 ]]; then # if-f one argument was given, print so many underscores
        for (( i = 0; i < $1; i++ )); do
            printf "_"
        done
    fi
}

# prints the padding on the left of the trees
draw_left_padding()
{
    level=$1
    height=$(( $max_height / 2**$level ))
    cols=$(( ( $width - ( $height * ( 2**( $level + 1 ) - 1 ) + 1 ) ) / 2 ))
    for (( line = 0; line < $height; line++ )); do
        print_ $cols
        printf "\n"
    done
}

# prints the padding on the right of the trees
draw_right_padding()
{
    level=$1
    height=$(( $max_height / 2**$level ))
    cols=$(( ( ( $width - ( $height * ( 2**( $level + 1 ) - 1 ) + 1 ) ) / 2 ) + 1 ))
    for (( line = 0; line < $height; line++ )); do
        print_ $cols
        printf "\n"
    done
}

# prints the padding between the trees
draw_middle_padding()
{
    level=$1
    height=$(( $max_height / 2**$level ))
    cols=$(( $height - 1 ))
    for (( line = 0; line < $height; line++ )); do
        print_ $cols
        printf "\n"
    done
}

# draws the rectangle area with the tree
draw_tree()
{
    level=$1
    height=$(( $max_height / 2**$level ))
    padding=$((0))
    # the top half
    for (( line = 0; line < $height / 2; line++ )); do
        print_ $padding # the padding on the left and bellow the tree
        printf "1"  # the left branch
        print_ $(( $height - 1 - (2 * $padding) ))    # the padding between the branches
        printf "1"  # the right branch
        print_ $padding # the padding on the right and bellow the tree
        printf "\n"

        (( padding++ ))
    done
    # the bottom half
    for (( line = 0; line < $height / 2; line++ )); do
        print_ $padding # the padding on the left of the stem
        printf "1"  # the stem
        print_ $padding # the padding on the right of the stem
        printf "\n"
    done
}

# draws blank lines
draw_blank()
{
    level=$1
    height=$(( $max_height / 2**$level ))
    for (( line = 0; line < $height; line++ )); do
        print_ $width
        printf "\n"
    done
}


draw_fractal()
{
    local level=$1
    local height=$(( $max_height / 2**$level ))
    if [[ $height -ge 2 ]]; then
        draw_fractal $(( $level + 1 ))
        if [[ $level -le $max_level ]]; then
            draw_left_padding $level > left
            draw_middle_padding $level > middle
            draw_right_padding $level > right
            draw_tree $level > tree

            cat left > semifinal

            for (( i = 0; i < (2**$level) - 1; i++ )); do
                echo "`paste -d '' semifinal tree`" > semifinal
                echo "`paste -d '' semifinal middle`" > semifinal
            done

            echo "`paste -d '' semifinal tree`" > semifinal
            echo "`paste -d '' semifinal right`" > semifinal

            echo "`cat final semifinal`" > final
        else
            draw_blank $level > blank
            echo "`cat final blank`" > final
        fi
    else
        print_ $width > final
        printf "\n" >> final
    fi
}

if [[ -e final ]]; then
    rm final
fi

read max_level
(( max_level-- ))

max_height=32
width=100

draw_fractal 0
cat final

# clean up
rm final semifinal left middle right tree
