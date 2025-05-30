(*exo 1*)
let rec inserer x l = 
  match l with 
  |[] ->x::[]
  |y::ll-> if x<y then x::l 
      else y::inserer x ll;;
  
let rec tri_insertion l=
  match l with 
  |[]-> []
  |x::ll -> inserer x (tri_insertion ll);;

(*exo 2*)


let rec decouper e l=
  match l with 
  |[] -> ([],[])
  |x::ll ->
      let (a,b)=decouper e ll in   (*jusqu'on arrive a ([],[])*)
      if x<e then (x::a,b) else (a,x::b)
                                
        
let rec concatenation l1 l2=
  match (l1,l2) with 
  |([],[]) -> []
  |(x::ll1,[]) -> l1
  |([],y::ll2) -> l2
  |(x::ll1,y::ll2) -> x::concatenation ll1 l2;;  
                        
let rec tri_rapide l=
  match l with 
  |[] ->[]
  |x::ll ->let (a,b)=decouper x ll in
      concatenation (tri_rapide a) (x::tri_rapide b);;
  
  (*exo 3*)
let rec decouper_bis l=
  match l with 
  |[]->([],[]) 
  |x::[]->([x],[])
  |x::y::ll -> let (a,b)=decouper_bis ll in
      (x::a,y::b)
      
let rec fusion l1 l2=
  match (l1,l2) with
  |([],[]) ->[]
  |(x::ll1,[])->l1
  |([],y::ll2)->l2
  |(x::ll1,y::ll2) ->if x<y then x::fusion ll1 l2
      else y::fusion l1 ll2
             
let rec tri_fusion l =
  match l with
  | [] | [_] -> l  (* Si la liste est vide ou à un seul élément, elle est déjà triée *)
  | _ ->
      let (a, b) = decouper_bis l in
      fusion (tri_fusion a) (tri_fusion b)
