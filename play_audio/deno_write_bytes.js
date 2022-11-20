var n = 100000;
var a_n_i16 = new Int16Array(n);
var n_i = 0;
var n_samp_val_max = (Math.pow(2, 16)-1)/2;
while(n_i < n){
    a_n_i16[n_i] = Math.sin(n_i*0.02)*n_samp_val_max;
    n_i+=1;
}
console.log(a_n_i16)
Deno.writeFile("sin_i16_bytes", a_n_i16,  { mode: 0o644 });
// play the bytes with 
//aplay -c 2 -f S16_LE -r 44100 ./sin_i16_bytes 
