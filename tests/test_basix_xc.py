# Copyright 2026 XMOS LIMITED.
# This Software is subject to the terms of the XMOS Public Licence: Version 1.

import subprocess
from pathlib import Path


def test_basix_from_xc():
    test_dir = Path(__file__).parent / "test_basix_xc"
    binary = test_dir / "bin" / "test_basix_xc.xe"
    expected = (test_dir / "pass.expect").read_text()

    result = subprocess.run(["xsim", str(binary)], capture_output=True, text=True)

    assert result.returncode == 0
    assert result.stdout == expected
