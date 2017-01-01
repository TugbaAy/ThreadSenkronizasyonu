# ThreadSenkronizasyonu

Fabrika problemimizde 3 adet makinamız bulunuyor. Bu makinalardan bir tanesi 3 saniye çalışarak
“&” ürününü , bir diğer makinamız 5 saniye çalışarak “$” ürününü, en son makinamız ise üretilen iki
ürünü birleştirip , ürüne id vererek 4 saniye çalıştıktan sonra gösterime sunuyor. Bunlara ek olan bir
makine ise üretimde etkili rol oynuyor. &makina’sı çalıştıktan sonra, &makine$ ‘ sına gidiyor ve &
üretiliyor. $ üretimi için de aynı kural geçerlidir.

&makina = 3 saniye / thread

$makina = 5 saniye / thread

&birlestir$ = 4 saniye / thread

&makina$ = üretimden sorumlu makina
