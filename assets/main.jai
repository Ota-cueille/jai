CONST_1 :: 500;
CONST_2 : string : "Hello world";

main :: (ac: i32, av: string[]) -> i32 {

	age := 25;
	is_major : bool = age >= 21;
	simple_calculus := ((age * 3) / 5 + 6);

	if(is_major) {
		print("Vous êtes majeurs");
	} else {
		print("Vous êtes mineurs");
	}

	return 0;
}
