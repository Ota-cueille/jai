# Jai Compiler in C/C++

1. Build Steps :

* open vscode with the `jai.code-workspace`
* import the vscode profile from `.vscode/jai.code-profile`
* change compiler path in `jai.code-workspace`
* launch `build (release)` task from vscode
* the compiler is in the `build/release` folder

2. What is Jai ?

   Jai is a programming language in developement created and designed by [Jonathan Blow](https://en.wikipedia.org/wiki/Jonathan_Blow).
3. Simple example :

```cs
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
```
