(* Functional implementation of basic statistics on a list of integers *)

let data = [5; 3; 9; 3; 8; 3; 1; 9]

(* Calculate the length of a list using fold *)
let length lst =
  List.fold_left (fun acc _ -> acc + 1) 0 lst

(* Sum of a list *)
let sum lst =
  List.fold_left ( + ) 0 lst

(* Mean as a float *)
let mean lst =
  let n = length lst in
  if n = 0 then
    invalid_arg "mean: empty list"
  else
    let s = sum lst in
    float_of_int s /. float_of_int n

(* Median: requires sorted list *)
let median lst =
  let sorted = List.sort compare lst in
  let n = length sorted in
  if n = 0 then invalid_arg "median: empty list"
  else
    let mid = n / 2 in
    if n mod 2 = 1 then
      (* odd length: take middle element *)
      float_of_int (List.nth sorted mid)
    else
      (* even length: average of two middle elements *)
      let a = List.nth sorted (mid - 1) in
      let b = List.nth sorted mid in
      (float_of_int a +. float_of_int b) /. 2.0

(* Build (value, count) list from a sorted list *)
let frequencies sorted_lst =
  let rec aux current count acc = function
    | [] ->
        (current, count) :: acc
    | x :: xs when x = current ->
        aux current (count + 1) acc xs
    | x :: xs ->
        aux x 1 ((current, count) :: acc) xs
  in
  match sorted_lst with
  | [] -> []
  | x :: xs ->
      List.rev (aux x 1 [] xs)

(* Find maximum count in (value, count) list *)
let max_count freq_list =
  List.fold_left (fun acc (_, c) -> max acc c) 0 freq_list

(* Extract all values that have the max frequency *)
let modes lst =
  match lst with
  | [] -> []
  | _ ->
      let sorted = List.sort compare lst in
      let freq_list = frequencies sorted in
      let m = max_count freq_list in
      List.fold_right
        (fun (v, c) acc -> if c = m then v :: acc else acc)
        freq_list
        []

let () =
  let m_mean = mean data in
  let m_median = median data in
  let m_modes = modes data in

  Printf.printf "Data: ";
  List.iter (fun x -> Printf.printf "%d " x) data;
  Printf.printf "\n";

  Printf.printf "Mean: %.3f\n" m_mean;
  Printf.printf "Median: %.3f\n" m_median;
  Printf.printf "Mode(s): ";
  List.iteri
    (fun i v ->
      if i > 0 then Printf.printf ", ";
      Printf.printf "%d" v)
    m_modes;
  Printf.printf "\n"
