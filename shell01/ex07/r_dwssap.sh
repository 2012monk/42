cat /etc/passwd \
      | sed '/^#/d' \
      | awk -F : "NR % 2 == 0 {print \$1}" \
      | rev \
      | sort -fr \
      | sed -n "$FT_LINE1,${FT_LINE2} p" \
      | xargs \
      | sed -e 's/\ /, /g' -e 's/$/./' \
      | tr -d '\n'
