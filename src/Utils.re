let s = str => React.string(str)

let padNumber = num =>
  if(int_of_string(num) < 10) {
    "0" ++ num;
  } else {
    num
  };

let formatTime = secounds => {
  let mins = secounds / 60;
  let secs = secounds mod 60;
  let minStr = mins |> string_of_int |> padNumber;
  let secString = secs |>string_of_int |> padNumber
  minStr ++ ":" ++ secString ;
};