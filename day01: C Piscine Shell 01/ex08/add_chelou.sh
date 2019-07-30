echo $FT_NBR1 + $FT_NBR2 \
  | tr "'"'\\"?!mrdoc' '0123401234' \
  | xargs -I{} echo 'ibase=5;obase=23;'{} \
  | bc \
  | tr '0123456789ABC' 'gtaio luSnemf'
