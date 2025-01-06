import json
from byu_pytest_utils import cache, compile_cpp, format_results_for_gradescope, run_exec, test_files, this_folder


@cache
def prod_bin():
    return compile_cpp('prod.cpp')


# Speed up interaction time
# _run_exec = run_exec
# run_exec = lambda *args, **kwargs: _run_exec(*args, **kwargs, read_timeout=0.1)

test_results = {
    'prod': [
        {
            'name': 'missing_args',
            'points': 2,
            'result': run_exec(
                prod_bin, 4,
                expected_stdio=test_files / 'prod_missing_args.stdout.txt'
            )
        },
        {
            'name': 'double1',
            'points': 2,
            'result': run_exec(
                prod_bin, 4.5, 5.5,
                expected_stdio=test_files / 'prod_double1.stdout.txt'
            )
        },
        {
            'name': 'double2',
            'points': 2,
            'result': run_exec(
                prod_bin, 158.45, 76.89,
                expected_stdio=test_files / 'prod_double2.stdout.txt'
            )
        },
        {
            'name': 'int1',
            'points': 2,
            'result': run_exec(
                prod_bin, 13, 37,
                expected_stdio=test_files / 'prod_int1.stdout.txt'
            )
        },
        {
            'name': 'int2',
            'points': 2,
            'result': run_exec(
                prod_bin, 25, 8,
                expected_stdio=test_files / 'prod_int2.stdout.txt'
            )
        }
    ]
}

# print(json.dumps(test_results, indent=2))

results = format_results_for_gradescope(test_results)

with open('results.json', 'w') as file:
    json.dump(results, file, indent=2)
