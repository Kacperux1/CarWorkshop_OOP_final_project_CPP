#!/usr/bin/env bash

# Updates the doxygen documentation, and copies it into the appropriate place
# in the gh-pages branch.

set -e

tempdir=`mktemp -d`
branch=`git rev-parse --abbrev-ref HEAD`

cp -r /mnt/c/Users/andrz/CLionProjects/Warsztaty/project/cmake-build-debug/library/cereal/doc/html/ ${tempdir}

git stash
git checkout gh-pages

rm -rf /mnt/c/Users/andrz/CLionProjects/Warsztaty/project/library/cereal/assets/doxygen
mkdir /mnt/c/Users/andrz/CLionProjects/Warsztaty/project/library/cereal/assets/doxygen
cp -r ${tempdir}/html/* /mnt/c/Users/andrz/CLionProjects/Warsztaty/project/library/cereal/assets/doxygen/

rm -rf ${tempdir}

git commit /mnt/c/Users/andrz/CLionProjects/Warsztaty/project/library/cereal/assets/doxygen

git checkout ${branch}
git stash apply
