const departments = [
	{
		code: 'CSE',
		name: 'B.Sc. in Computer Science and Engineering',
		duration: '4 years',
		semesters: '12 semesters',
		type: 'Tri-semester',
		creditHours: '154.5',
		admissionFee: '51,867 BDT',
		semesterCost: '75,000 BDT',
		totalCost: '9,31,800 BDT',
	},
	{
		code: 'SWE',
		name: 'B.Sc. in Software Engineering',
		duration: '4 years',
		semesters: '12 semesters',
		type: 'Tri-semester',
		creditHours: '145',
		admissionFee: '51,867 BDT',
		semesterCost: '70,000 BDT',
		totalCost: '8,71,200 BDT',
	},
	{
		code: 'CIS',
		name: 'B.Sc. in Computing and Information System',
		duration: '4 years',
		semesters: '12 semesters',
		type: 'Tri-semester',
		creditHours: '142',
		admissionFee: '50,667 BDT',
		semesterCost: '58,000 BDT',
		totalCost: '7,12,500 BDT',
	},
	{
		code: 'EEE',
		name: 'B.Sc. in Electrical and Electronic Engineering',
		duration: '4 years',
		semesters: '8 semesters',
		type: 'Bi-semester',
		creditHours: '144',
		admissionFee: '58,400 BDT',
		semesterCost: '92,000 BDT',
		totalCost: '7,63,200 BDT',
	},
	{
		code: 'CE',
		name: 'B.Sc. in Civil Engineering',
		duration: '4 years',
		semesters: '8 semesters',
		type: 'Bi-semester',
		creditHours: '147',
		admissionFee: '59,000 BDT',
		semesterCost: '91,000 BDT',
		totalCost: '7,53,075 BDT',
	},
	{
		code: 'BBA',
		name: 'Bachelor of Business Administration',
		duration: '4 years',
		semesters: '12 semesters',
		type: 'Tri-semester',
		creditHours: '130',
		admissionFee: '56,450 BDT',
		semesterCost: '60,000 BDT',
		totalCost: '7,43,200 BDT',
	},
	{
		code: 'B. Pharm',
		name: 'Bachelor of Pharmacy',
		duration: '4 years',
		semesters: '8 semesters',
		type: 'Bi-semester',
		creditHours: '160',
		admissionFee: '66,000 BDT',
		semesterCost: '1,22,500 BDT',
		totalCost: '10,08,200 BDT',
	},
	{
		code: 'NFE',
		name: 'Bachelor of Nutrition and Food Engineering',
		duration: '4 years',
		semesters: '12 semesters',
		type: 'Tri-semester',
		creditHours: '151',
		admissionFee: '49,200 BDT',
		semesterCost: '50,000 BDT',
		totalCost: '6,20,450 BDT',
	},
	{
		code: 'LAW',
		name: 'LL.B. (Hons.)',
		duration: '4 years',
		semesters: '12 semesters',
		type: 'Bi-semester',
		creditHours: '144',
		admissionFee: '1,30,000 BDT',
		semesterCost: '1,04,000 BDT',
		totalCost: '8,54,200 BDT',
	},
	{
		code: 'B. Arch.',
		name: 'Bachelor of Architecture',
		duration: '5 years',
		semesters: '10 semesters',
		type: 'Bi-semester',
		creditHours: '194',
		admissionFee: '55,100 BDT',
		semesterCost: '85,000 BDT',
		totalCost: '8,72,700 BDT',
	},
	{
		code: 'TE',
		name: 'B.Sc. in Textile Engineering',
		duration: '4 years',
		semesters: '8 semesters',
		type: 'Bi-semester',
		creditHours: '154',
		admissionFee: '59,200 BDT',
		semesterCost: '85,000 BDT',
		totalCost: '7,04,200 BDT',
	},
	{
		code: 'MCT',
		name: 'B.Sc. in Multimedia & Creative Technology',
		duration: '4 years',
		semesters: '12 semesters',
		type: 'Tri-semester',
		creditHours: '147',
		admissionFee: '50,467 BDT',
		semesterCost: '55,000 BDT',
		totalCost: '6,83,850 BDT',
	},
	{
		code: 'English',
		name: 'B.A. (Hons) in English',
		duration: '4 years',
		semesters: '12 semesters',
		type: 'Tri-semester',
		creditHours: '130',
		admissionFee: '52,000 BDT',
		semesterCost: '50,000 BDT',
		totalCost: '6,20,000 BDT',
	},
	{
		code: 'JMC',
		name: 'BSS in Journalism, Media and Communication',
		duration: '4 years',
		semesters: '12 semesters',
		type: 'Tri-semester',
		creditHours: '142',
		admissionFee: '52,067 BDT',
		semesterCost: '45,000 BDT',
		totalCost: '5,53,600 BDT',
	},
	{
		code: 'ESDM',
		name: 'B.Sc. in Environmental Science and Disaster Management',
		duration: '4 years',
		semesters: '12 semesters',
		type: 'Tri-semester',
		creditHours: '146',
		admissionFee: '46,867 BDT',
		semesterCost: '44,000 BDT',
		totalCost: '5,51,200 BDT',
	},
];

const seatData = [
	['CSE', '800'],
	['SWE', '600'],
	['CIS', '100'],
	['EEE', '400'],
	['CIVIL', '400'],
	['BBA', '300'],
	['PHARMACY', '100'],
	['NFE', '400'],
	['LAW', '100'],
	['B. Arch', '70'],
	['TE', '300'],
	['MCT', '50'],
	['English', '300'],
	['JMC', '50'],
	['ESDM', '100'],
];

const resultWaivers = [
	['Golden GPA-5 both in SSC and HSC', '75%', '3.50'],
	['Golden GPA-5 in HSC', '50%', '3.25'],
	['GPA-5 both in SSC and HSC', '35%', '3.25'],
	['GPA-5 in HSC', '25%', '3.00'],
	['4.90-4.99 in HSC', '20%', '3.00'],
	['4.75-4.89 in HSC', '10%', '3.00'],
	['Below 4.75 in HSC', '0%', '0.00'],
];

const cgpaWaivers = [
	['4.00', '50%'],
	['3.90 - 3.99', '30%'],
	['3.85 - 3.89', '20%'],
	['3.80 - 3.84', '10%'],
	['Below 3.80', '0%'],
];

const hallData = [
	{
		title: 'Male halls',
		subtitle: 'Yunus Khan Scholar Garden',
		items: [
			'Scholar Garden - 1: 1,600 students, 2 buildings',
			'Scholar Garden - 2: 2,000 students, 2 buildings',
			'Scholar Garden - 3: 500 students, 1 building',
			'Hall fee: BDT 3,500 per month, paid semester wise',
			'Registration fee: BDT 3,000',
		],
	},
	{
		title: 'Female halls',
		subtitle: 'Rowshan Ara Scholar Garden',
		items: [
			'Scholar Garden - 1: 1,000 students, 2 buildings',
			'Scholar Garden - 2: 1,200 students, 1 building',
			'Hall fee: BDT 3,500 per month, paid semester wise',
			'Registration fee: BDT 3,000',
		],
	},
];

const admissionContacts = [
	'+8801713493050  |  counselor@daffodilvarsity.edu.bd',
	'+8801713493051  |  counselor3@daffodilvarsity.edu.bd',
	'+8801847140017  |  counselor1@daffodilvarsity.edu.bd',
	'Helpline: +8809617901212',
	'Email: admission@daffodilvarsity.edu.bd',
];

const departmentGrid = document.getElementById('department-grid');
const departmentDetail = document.getElementById('department-detail');
const seatBody = document.getElementById('seat-body');
const resultWaiverTable = document.getElementById('result-waiver-table');
const cgpaWaiverTable = document.getElementById('cgpa-waiver-table');
const hallGrid = document.getElementById('hall-grid');
const admissionContactsList = document.getElementById('admission-contacts');
const admissionForm = document.getElementById('admission-form');
const admissionResult = document.getElementById('admission-result');
const deptSearch = document.getElementById('dept-search');

const formatDepartmentCard = (department) => `
	<button class="department-card" type="button" data-code="${department.code}">
		<span class="panel-label">${department.code}</span>
		<h3>${department.name}</h3>
		<p>${department.duration} · ${department.semesters} · ${department.type}</p>
	</button>
`;

const renderDepartmentDetail = (department) => {
	departmentDetail.innerHTML = `
		<span class="panel-label">Selected department</span>
		<h3>${department.code} - ${department.name}</h3>
		<p>Program structure and fee data reproduced from the C source menu.</p>
		<ul>
			<li><strong>Duration:</strong> ${department.duration}</li>
			<li><strong>Semesters:</strong> ${department.semesters}</li>
			<li><strong>Semester type:</strong> ${department.type}</li>
			<li><strong>Credit hours:</strong> ${department.creditHours}</li>
			<li><strong>Admission fee:</strong> ${department.admissionFee}</li>
			<li><strong>Semester cost:</strong> ${department.semesterCost}</li>
			<li><strong>Total cost:</strong> ${department.totalCost}</li>
		</ul>
	`;
};

const setActiveCard = (code) => {
	document.querySelectorAll('.department-card').forEach((card) => {
		card.classList.toggle('is-active', card.dataset.code === code);
	});
};

const renderDepartments = (items) => {
	departmentGrid.innerHTML = items.map(formatDepartmentCard).join('');
	const first = items[0];

	if (first) {
		renderDepartmentDetail(first);
		setActiveCard(first.code);
	} else {
		departmentDetail.innerHTML = `
			<span class="panel-label">Selected department</span>
			<h3>No matches found.</h3>
			<p>Try a different search term.</p>
		`;
	}
};

seatBody.innerHTML = seatData
	.map(
		([department, seats]) => `
			<tr>
				<td>${department}</td>
				<td>${seats}</td>
				<td>50 per section</td>
			</tr>
		`,
	)
	.join('');

resultWaiverTable.innerHTML = resultWaivers
	.map(
		([qualification, waiver, minCgpa]) => `
			<div class="row">
				<span>${qualification}</span>
				<strong>${waiver}</strong>
				<span>${minCgpa}</span>
			</div>
		`,
	)
	.join('');

cgpaWaiverTable.innerHTML = cgpaWaivers
	.map(
		([range, waiver]) => `
			<div class="row">
				<span>${range}</span>
				<strong>${waiver}</strong>
				<span>&nbsp;</span>
			</div>
		`,
	)
	.join('');

hallGrid.innerHTML = hallData
	.map(
		(hall) => `
			<article class="hall-card">
				<div class="hall-head">
					<div>
						<span class="panel-label">${hall.title}</span>
						<h3>${hall.subtitle}</h3>
					</div>
				</div>
				<ul>
					${hall.items.map((item) => `<li>${item}</li>`).join('')}
				</ul>
			</article>
		`,
	)
	.join('');

admissionContactsList.innerHTML = admissionContacts.map((contact) => `<li>${contact}</li>`).join('');

renderDepartments(departments);

departmentGrid.addEventListener('click', (event) => {
	const card = event.target.closest('.department-card');

	if (!card) {
		return;
	}

	const department = departments.find((entry) => entry.code === card.dataset.code);

	if (!department) {
		return;
	}

	renderDepartmentDetail(department);
	setActiveCard(department.code);
});

deptSearch.addEventListener('input', () => {
	const query = deptSearch.value.trim().toLowerCase();
	const filtered = departments.filter((department) => {
		return [department.code, department.name, department.type].some((field) =>
			field.toLowerCase().includes(query),
		);
	});

	renderDepartments(filtered);
});

admissionForm.addEventListener('submit', (event) => {
	event.preventDefault();

	const ssc = Number.parseFloat(document.getElementById('ssc-gpa').value);
	const hsc = Number.parseFloat(document.getElementById('hsc-gpa').value);
	const qualifies = Number.isFinite(ssc) && Number.isFinite(hsc) && ssc >= 4.5 && hsc >= 4.5;

	admissionResult.classList.remove('success', 'warning');
	admissionResult.classList.add(qualifies ? 'success' : 'warning');

	if (qualifies) {
		admissionResult.innerHTML = `
			<span class="panel-label">Checker output</span>
			<h3>Eligible for direct admission.</h3>
			<p>Your SSC and HSC GPAs both meet the 4.5 requirement. Final subject verification may still apply.</p>
		`;
		return;
	}

	admissionResult.innerHTML = `
		<span class="panel-label">Checker output</span>
		<h3>Direct admission not confirmed.</h3>
		<p>Both GPAs must be 4.5 or higher. Use the admission test contact details for the next step.</p>
	`;
});
