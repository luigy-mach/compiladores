
 void loop ( ) {
if ( Serial . available ( ) > 0 ) {
    estado = Serial . read ( ) ;
    //dfafsd
    if ( estado > 1 ) {
      switch ( estado ) {
          case 'w' :
          adelante ( vel ) ;
          break ;
      }
    }
  }
}
