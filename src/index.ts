import { open, load, DataType, close } from "ffi-rs";

const a = 15;
//const b = 5;

function loop(max: number): number {
	let i = max;
	let result = 1;
	while (i >= 2)
	{
		result *= i--;
	}
	return result;
}

open({
	library: "libsum", // key
	path: "./libsum.so" // path
});

const r = load({
	library: "libsum",
	funcName: "loop",
	retType: DataType.I64,
	paramsType: [DataType.I64],
	paramsValue: [a]
});

console.time("cpp");
console.log(r);
console.timeEnd("cpp");

console.time("ts");
console.log(loop(a));
console.timeEnd("ts");

close("libsum");