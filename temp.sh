#!/bin/bash

if [ $# -ne 2 ]
then
    echo "Not enough arguments"
    exit 1
fi

if ! command -v rsync > /dev/null 2>/dev/null
then
    echo "Please install rsync"
    exit 2
fi

curr_date=$(date)
rsync_options="-avb --delete"

$(which rsync) $rsync_options $1 $2 >> "backup_$curr_date.log"