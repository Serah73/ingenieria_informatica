'use strict'

let origen1 = document.getElementById('origen1')
let origen2 = document.getElementById('origen2')
let resultado1 = document.getElementById('resultado1')
let resultado2 = document.getElementById('resultado2')


let compra = {
    "Compra":[
        {
            "Nombre": "Objeto1",
            "Precio": "2.44"
        },
        {
            "Nombre": "Objeto2",
            "Precio": "3.94"
        }    
    ]
}
origen1.innerHTML = compra.Compra[0].Precio
origen2.innerHTML = compra.Compra[1].Precio


function igic ( ) {
  
  for( let i of compra.Compra ){
    i.Precio = (i.Precio * 1.07).toFixed(2)
  }
  
  //precioProducto += precioProducto*0.07
  resultado1.innerHTML = compra.Compra[0].Precio
  resultado2.innerHTML = compra.Compra[1].Precio
}