function swap(data, j) {
	let temp = data[j];
	data[j] = data[j + 1];
	data[j + 1] = temp;

	return data;
}

function bubble(data) {
	let length = data.length;

	for (let i = 0; i < length; i++) {
		for (let j = 0; j < length - i - 1; j++) {
			if (data[j] > data[j + 1]) {
				data = swap(data, j);
			}
		}
	}

	return data;
}

console.log(bubble([10, 9, 3, 3, 7, 8, 6, 11, 2]));
