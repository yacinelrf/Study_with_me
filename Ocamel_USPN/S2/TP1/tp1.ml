let rec fact n=
  if n=0 then 1
  else n*fact(n-1);;

let rec fact_acc n acc=
  if n=0 then acc
  else fact_acc(n-1)(n*acc);;
  
let rec append l1 l2=
  match l1 with 
    []->l2 |
    x::ll->x::append(ll)(l2);;

let rec rev l1 =
  match l1 with 
    [] -> l1 |
    x::ll -> append (rev ll) [x];;
  
let rec rev_acc l1 lacc=
  match l1 with 
    []->lacc |
    x::ll ->rev_acc ll (x::lacc);;
              
let rec inter l1 l2 =
  match (l1,l2) with 
    [],[] ->[]|
    [],l2 -> l2 |
    l1,[] ->l1 |
    x::ll1,y::ll2 ->if x=y then x::inter ll1 ll2
      else inter ll1 ll2;;
    
let rec union l1 l2=
  match (l1,l2) with 
    [],[] ->[]|
    [],x::ll2 -> l2|
    x::ll1,[] -> l1|
    x::ll1,y::ll2->if x=y then x::(inter ll1 ll2)
      else x::y::(inter ll1 ll2);;

let rec appartient x l =
  match l with
    [] ->false |
    y::ll ->if y=x then true
      else appartient x ll;;

let rec inter_2 l1 l2 =
  match (l1,l2) with 
    [],[] ->[]|
    [],x::ll2 -> []|
    x::ll1,[] -> []|
    x::ll1,y::ll2->if x=y  then x::(inter_2 ll1 ll2) 
      else if  appartient x l2 then x::(inter_2 ll1 l2)
      else if  appartient y l1 then y::(inter_2 l1 ll2)
      else inter_2 ll1 ll2;;

let rec union_2 l1 l2 =
  match (l1,l2) with 
    [],[] ->[]|
    [],l2 -> l2|
    l1,[] -> l1|
    x::ll1,y::ll2->
      if x=y  then x::(union_2 ll1 ll2) 
      else if appartient x l2 then union_2 ll1 l2
      else if appartient y l1 then union_2 l1 ll2
      else union_2 ll1 ll2;;
    
