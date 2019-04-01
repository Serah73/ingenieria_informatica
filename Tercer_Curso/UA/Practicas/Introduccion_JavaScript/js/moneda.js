var libra = document.getElementById('libra')
var dolar = document.getElementById('dolar')
var bolivar = document.getElementById('bolivar')

function cambiarMoneda ( moneda ) {
    libra.innerHTML = (moneda * 0.85).toFixed(2)
    bolivar.innerHTML = (moneda * 7.86).toFixed(2)
    dolar.innerHTML = (moneda * 1.14).toFixed(2)
}