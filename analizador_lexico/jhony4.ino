
    if (estado != -1){
      switch(estado){
          case 'w':
          adelante(vel); 
          break;
          case 's':  
          atras(vel); 
          break;

          case 'c':
          parar();
          break;          
      }
    }
  }
}

