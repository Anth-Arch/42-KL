cat /etc/passwd | sed 's/:*:.*//' | awk "((NR % 2)-1) == 0" | rev | sort -r | awk -v line1="$FT_LINE1" -v line2="$FT_LINE2" 'NR >= line1 && NR<= line2' | tr '\n' ', ' | sed 's/.$/.\n/'
