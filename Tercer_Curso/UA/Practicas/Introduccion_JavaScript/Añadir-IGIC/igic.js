let resultado1 = document.getElementById('resultado1')
let resultado2 = document.getElementById('resultado2')

let file = require('Compra.json')
let compra = JSON.parse(file)


function igic ( ) {
  
  for( let i of compra.Compra ){
    i.Precio *= 1.07
  }
  
  //precioProducto += precioProducto*0.07
  resultado1.innerHTML = compra[0].Precio
  resultado2.innerHTML = compra[1].Precio
}