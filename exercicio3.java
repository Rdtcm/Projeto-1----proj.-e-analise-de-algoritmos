public class exercicio3 {
	public static void main(String[] args) {
		
 		String ex3 = "cacocacocacorenanuvauva";
 		String guarda ="";
 		String fim = "";
 		
 		// boolean teste = false;
 		int count = 0 ;
 		for(int i = 0 ; i<ex3.length();i++) {
 			
 			int lenght = 0;
 			String test = "";
 			String test2 = "";
 			String mudar ="";
 			String check ="";
 			String test3 = "";
 			
 			for(int k = 0; k <i ; k++) {
 				test = ex3.substring(k,i);
 				lenght = test.length();
 				if(i+lenght>ex3.length()) {
 					
 				}else {
 				test2 = ex3.substring(i,i+lenght);
 				
 				if(test.contains("_")) {
 					
 				}else
 				if(test.equals(test2) ) {
 					
 					for(int j = 0; j<ex3.length() ; j++) {

 						if(j+test.length()>ex3.length()) {}else {
							
 						 test3 = ex3.substring(j,j+test.length());
 						 
 						 if(test2.equals(test3)){
 							count++; 
 						 }
 						}
 						
 					}
 					for(int l = 0 ; l<test2.length();l++) {
 						mudar += "_";
 					}
 					ex3 = ex3.replace(test2, mudar);
 					check = ex3.substring(0,i);
 					check = check.replace("_", "");
 					 if(!check.isEmpty()) {
 						fim += check + "1";
 					 }
 					fim += test2 + count;
 					count = 0;
 					mudar ="";
 				}
 				
 				}
 				
 			}
 		}
 		System.out.println(fim);
 	}
}
 	