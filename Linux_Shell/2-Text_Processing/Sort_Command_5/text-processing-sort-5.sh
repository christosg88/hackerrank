#!/bin/bash
sort -n -r -t $'\t' -k2,2 - # sort numerically in reverse order from the second to the second column using a tab as a delimiter
