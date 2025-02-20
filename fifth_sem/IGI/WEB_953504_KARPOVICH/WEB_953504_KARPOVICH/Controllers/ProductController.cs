﻿using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using WEB_953504_KARPOVICH.Data;
using WEB_953504_KARPOVICH.Entities;
using WEB_953504_KARPOVICH.Extensions;
using WEB_953504_KARPOVICH.Models;

namespace WEB_953504_KARPOVICH.Controllers
{
    public class ProductController : Controller
    {
        ApplicationDbContext _context;

        int _pageSize;

        public ProductController(ApplicationDbContext context)
        {
            _pageSize = 3;
            _context = context;
        }

        [Route("Catalog")]
        [Route("Catalog/Page_{pageNo}")]
        public IActionResult Index(int? brand, int pageNo)
        {
            var notebooksFiltered = _context.Notebooks.Where(d => !brand.HasValue || d.BrandId == brand.Value);

            // Put a list of brands in ViewData
            ViewData["Brands"] = _context.Brands;

            // Get the id of the current brand and put it in TempData
            ViewData["CurrentBrand"] = brand ?? 0;

            var model = ListViewModel<Notebook>.GetModel(notebooksFiltered, pageNo, _pageSize);
            if (Request.IsAjaxRequest())
                return PartialView("_listpartial", model);
            else
                return View(model);
        }
    }
}
